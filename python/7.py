# 数据增强，让数据更加多样化

from PIL import Image
from torchvision import transforms
from IPython.display import display

# 图像处理工具之 torchvision.transforms

img = Image.open('./1.jpg')
# display(img)
print(type(img))  # PIL.Image.Image是PIL.JpegImagePlugin.JpegImageFile的基类
'''
输出: 
<class 'PIL.JpegImagePlugin.JpegImageFile'>
'''
# 数据类型转换
# 如何将PIL.Image和Numpy.ndarray转换为torch.Tensor呢？需要使用transforms.ToTensor()函数

img1 = transforms.ToTensor()(img)
print(type(img1))  # <class 'torch.Tensor'>

# tensor转换为PIL.Image
img2 = transforms.ToPILImage()(img1)  # PIL.Image.Image
# pil.image

# print(type(img2))  # <class 'PIL.Image.Image'>


# 对PIL.IMG和Tensor进行变换
# 标准化是指每一个数据点减去所在通道的平均值，再除以所在通道的标准差，数学的计算公式如：output=(input-mean)/std
# 而对图像进行标准化，就是对图像每个通道利用均值和标准差进行正则化。这样做的好处是可以使得每个通道的数据分布更加均匀，从而使得训练更加稳定。
# 定义化标准化函数
norm_oper = transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])
tensor_norm = norm_oper(img1)

img2 = transforms.ToPILImage()(tensor_norm)
# display(img2)
