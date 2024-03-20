import openai
import os
from openai.embeddings_utils import cosine_similarity, get_embedding

# 获取访问open ai的密钥
openai.api_key = os.getenv("OPENAI_API_KEY")
# 选择使用最小的ada模型
EMBEDDING_MODEL = "text-embedding-ada-002"

# 获取"好评"和"差评"的
positive_review = get_embedding("好评")
middle_review = get_embedding("一般")
negative_review = get_embedding("差评")

positive_example = get_embedding("你们的老师很负责任，很关心我们家的孩子")
middle_example = get_embedding("你们的课，一般般吧，学习不学习也就那样了")
negative_example = get_embedding("你从来都没有问过我们家孩子的学习状况，就每次报课花钱的时候，才会给我打电话")


'''
cosine_similarity()是一个用于计算两个向量之间余弦相似度的接口。
余弦相似度是一种常用的相似度度量方法，它可以用于比较两个向量之间的相似程度。
在自然语言处理中，余弦相似度通常用于计算两个文本之间的相似度，例如文本分类、信息检索、推荐系统等任务。
通过使用 cosine_similarity 接口，可以计算出两个向量之间的余弦相似度，从而判断它们之间的相似程度。
余弦相似度的取值范围在 -1 到 1 之间，值越接近 1 表示两个向量越相似，值越接近 -1 表示两个向量越不相似。
'''


def get_score(sample_embedding):
    return cosine_similarity(sample_embedding, positive_review) - cosine_similarity(sample_embedding, negative_review)


positive_score = get_score(positive_example)
middle_score = get_score(middle_example)

negative_score = get_score(negative_example)

print("好评例子的评分 : %f" % (positive_score))

print("中评例子的评分 : %f" % (middle_score))

print("差评例子的评分 : %f" % (negative_score))
