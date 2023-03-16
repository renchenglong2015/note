# 数据读取
import torch
from torch.utils.data import Dataset


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

print(data_tensor, target_tensor)
