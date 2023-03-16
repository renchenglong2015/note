# 卷积计算公式
import torch
import torch.nn as nn

input_feat = torch.tensor(
    [[4, 1, 7, 5], [4, 4, 2, 5], [7, 7, 2, 4], [
        1, 0, 2, 4]], dtype=torch.float32).unsqueeze(0).unsqueeze(0)

conv2d = nn.Conv2d(1, 1, (2, 2), stride=1, padding='same', bias=False)


kernels = torch.tensor([[[[1, 0], [2, 1]]]], dtype=torch.float32)
conv2d.weight = nn.Parameter(kernels, requires_grad=False)
print(input_feat)
print(input_feat.shape)

output = conv2d(input_feat)

print(output)
# pytorch 输入tensor的维度信息是    (batch_size, channel, height, width)
# 但是我们在我们的例子中只给定了高与宽。
