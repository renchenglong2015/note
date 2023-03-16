# 常见的网络模型，都放在了torchvision.models中,这些网络模型可以解决以下问题：图像分类，图像分割，物体检测和视频分类。
import torchvision.models as models
import torchvision
print(torchvision.__version__)

# 在版本（v0.10.0）的 Torchvision 中，新增了图像语义分割、物体检测和视频分类的相关网络，
# 并且在图像分类中也新增了 GoogLeNet、ShuffleNet 以及可以使用于移动端的 MobileNet 系列。这些新模型，都能让我们站在巨人的肩膀上看世界。

# 实例化一个googlenet模型

# torchvision.models除了包含了定义好的模块以外，还为我们提供了预训练好的模型。
# 我们可以直接导入训练好的模型使用。
googlenet = models.googlenet(pretrained=True)
vgg16 = models.vgg16(pretrained=True)

# torchvision.models所有训练好的模型都是在imgnet数据集上训练的。

# 模型微调
# 简单来讲就是先在一个比较通用，宽泛的数据集上进行大量的训练，然后再在具体的数据集上进行训练。
# 为什么模型微调如此有效呢，因为我们相信同样是处理图片分类任务的，两个模型。参数是有相似性的。
# 也就是说，我们可以利用已经训练好的模型的参数，来初始化我们的模型，这样就可以加快我们的训练速度。

# 提取分类层输入参数
fc_in_features = googlenet.fc.in_features
print(fc_in_features)
fc_out_features = googlenet.fc.out_features
print(fc_out_features)
