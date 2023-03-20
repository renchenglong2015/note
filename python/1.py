from matplotlib import pyplot as plt
import cv2
import numpy as np
from PIL import Image

# pytorch 深度学习实战 numpY

im = Image.open('./1.jpg')
# print(im.size)


im_pillow = np.asarray(im)

im_pillow.shape
# print(im_pillow.shape)

im_cv2 = cv2.imread('1.jpg')
# print(type(im_cv2))

# print(im_cv2.shape)

"""
(318, 116)
(116, 318, 3)
<class 'numpy.ndarray'>
(116, 318, 3)
"""

# 取图片第 0 个通道的所有数据。

# 这是Numpy的切片索引语法，
# 其中`:`表示选择整个轴，而逗号`,`则表示选择不同的轴。
# 例如，`pillow[:, :, 0]`表示从数组`pillow`中选择所有行和列，并选择第三个轴的第一个元素，即R通道。
# 这将返回一个二维数组，其中每个元素都是原数组中对应位置的R通道的值。
im_pillow_c1 = im_pillow[:, :, 0]
im_pillow_c2 = im_pillow[:, :, 1]
im_pillow_c3 = im_pillow[:, :, 2]


#arr = np.arange(12)
#b = arr[:, np.newaxis]
# print(b)

#arr_3d = arr.reshape((2, 2, 3))
#
#im_pillow_c1 = arr_3d[:, :, 0]
#zeors = np.zeros((arr_3d.shape[0], arr_3d.shape[1], 1))
# print(zeors)

# print(im_pillow_c2)
# print(im_pillow_c1.shape)

# print(im_pillow_c2.shape)

# print(im_pillow_c3.shape)

# 生成全零数组

zeros = np.zeros((im_pillow.shape[0], im_pillow.shape[1], 1))

# 然后我们只需要将全0数组与im_pillow_c1,im_pillow_c2,im_pillow_c3进行拼接后
# 就可以获得相应通道的数据

# 我们可以使用np.newaxis增加一个维度。
im_pillow_c1 = im_pillow_c1[:, :, np.newaxis]
# print(im_pillow_c1.shape)

im_pillow_c1_3ch = np.concatenate((im_pillow_c1, zeros, zeros), axis=2)

# print(im_pillow_c1_3ch)


# 方法2直接赋值 ，其实我们完全可以生成一个im_pillow的全零数组，然后将每个通道的数值赋值为im_pillow_c1
# im_pillow_c2,im_pillow_c3。

im_pillow_c2_3ch = np.zeros(im_pillow.shape)
im_pillow_c2_3ch[:, :, 1] = im_pillow_c2

im_pillow_c3_3ch = np.zeros(im_pillow.shape)
im_pillow_c3_3ch[:, :, 2] = im_pillow_c3

# subplot(nrows, ncols, index)：创建子图，nrows和ncols分别为子图的行数和列数，index为子图的编号。

plt.subplot(2, 2, 1)
plt.title('Origin Image')
plt.imshow(im_pillow)
plt.axis('off')
plt.subplot(2, 2, 2)
plt.title('Red Channel')
plt.imshow(im_pillow_c1_3ch.astype(np.uint8))
plt.axis('off')
plt.subplot(2, 2, 3)
plt.title('Green Channel')
plt.imshow(im_pillow_c2_3ch.astype(np.uint8))
plt.axis('off')
plt.subplot(2, 2, 4)
plt.title('Blue Channel')
plt.imshow(im_pillow_c3_3ch.astype(np.uint8))
plt.axis('off')
plt.savefig('./rgb_pillow.png', dpi=150)

# 深拷贝，浅拷贝
im = Image.open('./1.jpg')
im_pillow = np.array(im)
im_pillow[:, :, 1:] = 0
# ValueError: assignment destination is read-only 报错提示数组是制度数组，没办法修改。我们可以使用copy来复制一个数组。
# 浅拷贝：与原数组共享数据的数组,请注意只是共享数据，没有共享形状。
# 深拷贝：完全复制原有数组，创建一个新的数组。

# print(im_pillow)


a = np.arange(6)
# print(a.shape)
# print(a)
b = a.view()
# print(b)
b.shape = 2, 3
# print(b)
# print(a)
b[0, 0] = 111

# print(b)
# print(a)


# 模型评估，在模型评估时，我们一般会将模型输出转换为对应的标签。
# 假设我们的问题是将图片分为两个类别，包含即可时间与不包含的图片，模型会输出形状为（2，）的数组，我们把它叫做probs,
# 它存储了两个概率，我们假设索引为0的概率是包含即可时间图片的概率，另一个是其他图片的概率。他们两个的概率和为1.
# 如果即可时间对应的概率大，则可以推断该图片包含即可时间的图片，否则为其他图片。

# 简单的做法就是判断probs[0]是否大于0.5，如果大于0.5，则是我们认为需要寻找的。

# Argmax vas Argmin ：求最大最小值的索引。

probs = np.array([0.075, 0.15, 0.075, 0.15, 0.0, 0.05, 0.05, 0.2, 0.25])
print(np.argmax(probs))  # 输出 8
print(np.argmin(probs))  # 输出 4


probs_idx_sort = np.argsort(-probs)  # 注意，加了负号，是按降序排序
print(probs_idx_sort)
# 输出：array([8, 7, 1, 3, 0, 2, 5, 6, 4])
# 概率最大的前三个值的坐标
print(probs_idx_sort[:3])
# 输出：array([8, 7, 1])


# 每课一练
# 给定数组 scores，形状为（256，256，2），
# scores[: , :, 0] 与 scores[:, :, 1]对应位置元素的和为 1，
# 现在我们要根据 scores 生产数组 mask，要求 scores 通道 0 的值如果大于通道 1 的值，则 mask 对应的位置为 0，否则为 1。

scores = np.random.rand(256, 256, 2)


scores[:, :, 1] = 1 - scores[:, :, 0]

mask = np.argmax(scores, axis=2)


print(mask)
