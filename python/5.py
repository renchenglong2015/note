import torch

# Tensor的连接操作
a = torch.ones(3, 3)
b = 2*torch.ones(3, 3)

#print(a, '\n', b)
c = torch.cat((a, b), dim=1)
# print(c)

# stack 操作

a = torch.arange(0, 4)
b = torch.arange(5, 9)

c = torch.stack((a, b), dim=1)
# print(c)
# 切分操作
# chunk

a = torch.arange(0, 10)
b = torch.chunk(a, 2, dim=0)
# print(b)


a = torch.ones(3, 3)
# print(a)
b = torch.chunk(a, 3, dim=1)
# print(b)


# split

a = torch.rand(4, 4)
b = torch.split(a, 2, dim=0)
#print(a, "\n", b)

# unbind

a = torch.arange(0, 16).view(4, 4)
b = torch.unbind(a, dim=1)
#print(a, "\n", b)

# 索引操作

a = torch.arange(0, 16).view(4, 4)
b = torch.index_select(a, dim=0, index=torch.tensor([1, 3]))
c = torch.index_select(a, dim=1, index=torch.tensor([1, 3]))
#print(a, "\n", b, "\n", c)


# 根据条件判断选择
a = torch.rand(5)
b = torch.where(a > 0.5, a, torch.ones_like(a))
c = torch.masked_select(a, a > 0.3)
print(a, "\n", b, "\n", c)
