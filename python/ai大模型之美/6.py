
import openai
import os

openai.api_key = os.environ.get("OPENAI_API_KEY")

'''
openai.ChatCompletion.create(
    model="gpt-3.5-turbo",
    messages=[
        {"role": "system", "content": "You are a helpful assistant."},
        {"role": "user", "content": "Who won the world series in 2020?"},
        {"role": "assistant",
            "content": "The Los Angeles Dodgers won the World Series in 2020."},
        {"role": "user", "content": "Where was it played?"}
    ]
)

1.role 这个字段一共有三个角色可以选择，分别是 system 代表系统，user 代表用户，而 assistant 则代表 AI 的回答。

2.当role 是system时，content 代表的是我们给ai的一个指令，也就是告诉ai应该如何回答用户的问题。比如我们希望ai都用
中文回答用户的问题，我们就可以在content里面写“你是一个只会用中文回答问题的助手”。即使英文问问题，ai的回复也是中文。

3.当role是user或者assistant的时候，content里面代表的就是用户和ai对话内容。

'''


'''
1.我们封装了一个conversation类,它的init方法接受两个参数,一个是prompt,一个是num_of_round,分别表示对话的开头和对话的轮数.
2.conv.ask方法接受一个参数,即用户的输入,然后调用openai的api,返回一个回复.
3.每次调用
'''


class Conversation:
    def __init__(self, prompt, num_of_round):
        self.prompt = prompt
        self.num_of_round = num_of_round
        self.messages = []
        self.messages.append({"role": "system", "content": self.prompt})

    def ask(self, question):
        try:
            self.messages.append({"role": "user", "content": question})
            response = openai.ChatCompletion.create(
                model="gpt-3.5-turbo",
                messages=self.messages,
                temperature=0.5,
                max_tokens=2048,
                top_p=1,
            )
        except Exception as e:
            print(e)
            return e

        message = response["choices"][0]["message"]["content"]
        self.messages.append({"role": "assistant", "content": message})

        if len(self.messages) > self.num_of_round * 2 + 1:
            del self.messages[1:3]  # Remove the first round conversation left.
        return message


prompt = """你是一个中国厨师，用中文回答做菜的问题。你的回答需要满足以下要求:
1. 你的回答必须是中文
2. 回答限制在100个字以内"""
conv1 = Conversation(prompt, 2)
# question1 = "你是谁？"
# print("User : %s" % question1)
# print("Assistant : %s\n" % conv1.ask(question1))

# question2 = "请问宫保鸡丁怎么做？"
# print("User : %s" % question2)
# print("Assistant : %s\n" % conv1.ask(question2))

# question3 = "那鱼香肉丝呢？"
# print("User : %s" % question3)
# print("Assistant : %s\n" % conv1.ask(question3))

question4 = "我问你的第一个问题是什么？"
print("User : %s" % question4)
print("Assistant : %s\n" % conv1.ask(question4))
