from flask import Flask, request, jsonify
from transformers import AutoModelForCausalLM, AutoTokenizer
import torch
from flask_cors import CORS

# 创建 Flask 应用并添加 CORS 支持
app = Flask(__name__)
CORS(app)

# 加载模型和分词器
model_name = "F:\\charGLM2\\ChatGLM2-6B\\models\\chatgml2"
tokenizer = AutoTokenizer.from_pretrained(model_name, trust_remote_code=True)
model = AutoModelForCausalLM.from_pretrained(model_name, trust_remote_code=True).cuda()
model.eval()

# 定义API端点
@app.route('/api/predict', methods=['POST'])
def api_predict():
    # 从POST请求的JSON体中获取用户输入
    data = request.json
    input_text = data['input']
    
    # 编码用户输入，生成模型所需的输入格式
    inputs = tokenizer.encode(input_text, return_tensors='pt').to('cuda')
    
    # 使用模型生成预测结果
    with torch.no_grad():
        outputs = model.generate(inputs, max_length=50, do_sample=False) #top_p=0.8, temperature=0.95)
    
    # 将预测结果转换为文本
    response_text = tokenizer.decode(outputs[0], skip_special_tokens=True)
    
    # 返回JSON格式的预测结果
    return jsonify({'response': response_text})

# 启动Flask应用
if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0', port=8000)
