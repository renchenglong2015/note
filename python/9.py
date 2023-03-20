# 卷积计算公式
import torch
import torch.nn as nn


# 输出特征图的通道数由卷积核的个数决定，所以说卷积核的个数为n。
# 根据卷积计算的定义，输入特征图有m个通道，所以每个卷积核里面也有m个通道
# 所以我们需要n个卷积核，每个卷积核的大小为m * k * k
# 也就是说卷积核的形状为(n, m, k, k)
# 卷积核1与全部输入图进行卷积计算，得到输出特征图中的第一个通道的数据，
# 卷积核2与全部输入图进行卷积计算，得到输出特征图中的第二个通道的数据，以此类推，最后得到输出特征图的n个通道的数据。
# 在开篇的例子中。输入只有一个通道，现在有多个通道了该如何计算。其实计算方式类似，输入特征中的每一通道都与卷积核中的每一通道进行卷积计算，然后将结果相加，得到输出特征图中的每一个通道的数据。

input_feat = torch.tensor(
    [[4, 1, 7, 5],
     [4, 4, 2, 5],
     [7, 7, 2, 4],
     [1, 0, 2, 4]],
    dtype=torch.float32).unsqueeze(0).unsqueeze(0)

conv2d = nn.Conv2d(1, 1, (2, 2), stride=1, padding='same', bias=False)


kernels = torch.tensor([[[[1, 0], [2, 1]]]], dtype=torch.float32)
conv2d.weight = nn.Parameter(kernels, requires_grad=False)
print(input_feat)
print(input_feat.shape)

output = conv2d(input_feat)

print(output)
# pytorch 输入tensor的维度信息是    (batch_size, channel, height, width)
# 但是我们在我们的例子中只给定了高与宽。
