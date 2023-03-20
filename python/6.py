# 数据读取
import torchvision
import torch
from torch.utils.data import Dataset
from torch.utils.data import DataLoader


class DiabetesDataset(Dataset):

    def __init__(self, data_tensor, target_tensor):
        self.data_tensor = data_tensor
        self.target_tensor = target_tensor

    def __len__(self):
        return self.data_tensor.size(0)

    # 返回索引的数据与标签
    def __getitem__(self, idx):
        return self.data_tensor[idx], self.target_tensor[idx]


data_tensor = torch.randn(10, 3)
target_tensor = torch.randint(2, (10,))

my_dataset = DiabetesDataset(data_tensor, target_tensor)
print(data_tensor, target_tensor)


tensor_dataloader = DataLoader(dataset=my_dataset,  # 传入的数据集, 必须参数
                               batch_size=2,       # 输出的batch大小
                               shuffle=True,       # 数据是否打乱
                               num_workers=0)      # 进程数, 0表示只有主进程

# 以循环形式输出
# for data, target in tensor_dataloader:
#    print(data, target)
'''
输出:
tensor([[-0.1781, -1.1019, -0.1507],
        [-0.6170,  0.2366,  0.1006]]) tensor([0, 0])
tensor([[ 0.9451, -0.4923, -1.8178],
        [-0.4046, -0.5436, -1.7911]]) tensor([0, 0])
tensor([[-0.4561, -1.2480, -0.3051],
        [-0.9738,  0.9465,  0.4812]]) tensor([1, 0])
tensor([[ 0.0260,  1.5276,  0.1687],
        [ 1.3692, -0.0170, -1.6831]]) tensor([1, 0])
tensor([[ 0.0515, -0.8892, -0.1699],
        [ 0.4931, -0.0697,  0.4171]]) tensor([1, 0])
'''

# 输出一个batch
#print('One batch tensor data: ', iter(tensor_dataloader).next())
'''
输出:
One batch tensor data:  [tensor([[ 0.9451, -0.4923, -1.8178],
        [-0.4046, -0.5436, -1.7911]]), tensor([0, 0])]
'''


# 以MNIST为例
mnist_dataset = torchvision.datasets.MNIST(root='./data',
                                           train=True,
                                           transform=None,
                                           target_transform=None,
                                           download=True)
mnist_dataset_list = list(mnist_dataset)

print("Image label is:", mnist_dataset_list[0][0])
