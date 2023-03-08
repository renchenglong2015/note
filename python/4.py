import torch

# tensor是深度学习框架中极为基础的概念。
# 标量可以组合成向量，向量可以组合成矩阵。那么是否看作是一种数据形式呢？
# 答案是可以的，

# torch.tensor(data, dtype=None, device=None, requires_grad=False)

# torch.from_numpy(ndarry)


# 创建特殊形式的tensor

# 创建 零矩阵
a = torch.zeros(3)
# print(a)  tensor([0., 0., 0.])

# 创建单位矩阵 单位矩阵是值主对角线上的元素都为1的矩阵

a = torch.eye(3)
'''
print(a)
tensor([[1., 0., 0.],
        [0., 1., 0.],
        [0., 0., 1.]])
'''
# 创建全一矩阵 Tensor：全一矩阵顾名思义，就是所有的元素都为 1 的矩阵。

a = torch.ones(4)

# print(a)  tensor([1., 1., 1., 1.])

# 创建随机矩阵 Tensor：在 PyTorch 中有几种较为经常使用的随机矩阵创建方式，分别如下。
a = torch.rand(4)  # 用于生成数据类型为浮点型且维度指定的随机 Tensor，随机生成的浮点数据在 0~1 区间均匀分布。
# print(a)  tensor([0.9438, 0.5300, 0.3972, 0.3416])


a = torch.randn(4)
# print(a)  torch.randn 用于生成数据类型为浮点型且维度指定的随机 Tensor，随机生成的浮点数的取值满足均值为 0、方差为 1 的标准正态分布。
# tensor([-1.0062,  1.4665,  1.3043, -0.4503])

# torch.normal 用于生成数据类型为浮点型且维度指定的随机 Tensor，可以指定均值和标准差。
# a = torch.normal(0, 1, 4)
#a = torch.randint(1, 2, 4)
# print(a)
# tensor([-1.0062,  1.4665,  1.3043, -0.4503])


# tensor的转换
# Int 与 Tensor 的转换：
a = torch.tensor(1)
b = a.item()
# print(b)

# list 与 tensor 的转换：
a = torch.tensor([1, 2, 3])
b = a.numpy().tolist()
# print(b)
# Tensor的常用操作

a = torch.zeros([2, 3, 5])
# print(a.shape)  # torch.Size([2, 3, 5])
# print(a.size())  # torch.Size([2, 3, 5])
# print(a.numel())  # 30

# 矩阵转秩
x = torch.rand(2, 3, 5)
# print(x.shape)  # torch.Size([2, 3, 5])
y = x.permute(1, 0, 2)
# print(y.shape)  # torch.Size([3, 2, 5])
x = x.transpose(1, 2)
# print(x.shape)  # torch.Size([2, 5, 3])


# 矩阵形状变换

x = torch.randn(4, 4)
# print(x)
x = x.view(2, 8)
# print(x)
x = x.permute(1, 0)
# print(x)
# x.view(4, 4)  # 其实就是因为 view 不能处理内存不连续 Tensor 的结构。
x = x.reshape(4, 4)
# print(x)


# 增减维度
x = torch.rand(2, 2, 3)
print(x.shape)
x = x.squeeze(1)
print(x.shape)
