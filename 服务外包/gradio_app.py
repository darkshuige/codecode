from transformers import AutoModel, AutoTokenizer
import gradio as gr
from utils import load_model_on_gpus, parse_text, postprocess

# 加载模型和分词器
tokenizer = AutoTokenizer.from_pretrained("F:\charGLM2\ChatGLM2-6B\models\chatgml2", trust_remote_code=True)
model = AutoModel.from_pretrained("F:\charGLM2\ChatGLM2-6B\models\chatgml2", trust_remote_code=True).cuda()
model = model.eval()

# 重写Gradio Chatbot的postprocess方法
gr.Chatbot.postprocess = postprocess

# 定义预测函数
def gradio_predict(input, chatbot, max_length, top_p, temperature, history, past_key_values):
    chatbot.append((parse_text(input), ""))
    for response, history, past_key_values in model.stream_chat(
        tokenizer, input, history, past_key_values=past_key_values,
        return_past_key_values=True, max_length=max_length, top_p=top_p,
        temperature=temperature):
        chatbot[-1] = (parse_text(input), parse_text(response))
        yield chatbot, history, past_key_values

# 定义重置用户输入和状态的函数
def reset_user_input():
    return gr.update(value='')

def reset_state():
    return [], [], None

# 创建Gradio界面
with gr.Blocks() as demo:
    gr.Markdown("<h1 align='center'>ChatGLM2-6B</h1>")
    chatbot = gr.Chatbot()
    user_input = gr.Textbox(show_label=False, placeholder="请输入...", lines=2)
    submit_button = gr.Button("提交")
    clear_button = gr.Button("清除历史")
    max_length = gr.Slider(0, 32768, value=8192, step=1.0, label="最大长度")
    top_p = gr.Slider(0, 1, value=0.8, step=0.01, label="Top P")
    temperature = gr.Slider(0, 1, value=0.95, step=0.01, label="温度")

    submit_button.click(
        gradio_predict,
        inputs=[user_input, chatbot, max_length, top_p, temperature, gr.State([]), gr.State(None)],
        outputs=[chatbot]
    )
    clear_button.click(
        reset_state,
        outputs=[chatbot, gr.State([]), gr.State(None)]
    )

# 启动Gradio界面
if __name__ == "__main__":
    demo.launch()
