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
print(im_pillow_c1.shape)

im_pillow_c1_3ch = np.concatenate((im_pillow_c1, zeros, zeros), axis=2)

print(im_pillow_c1_3ch)


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
