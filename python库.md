# `pyautogui`图像识别以及点击等功能

* 



#  `pytesseract`:ocr库

* Pytesseract 是一个 Python 的 OCR（Optical Character Recognition，光学字符识别）库，可以用来将图片、PDF 等文件中的文本转换为可编辑的文本格式。它基于 Google 的 Tesseract OCR 引擎，支持多种语言，并且具有较高的准确率和稳定性。

  ```python
  pip install pytesseract
  # 有一点需要注意的是，Pytesseract 库依赖于 Tesseract OCR 引擎，因此在安装 Pytesseract 之前请确保已安装 Tesseract OCR。如果还没有安装 Tesseract OCR，请先下载和安装它，然后再安装 Pytesseract。
  ```

  

需要安装Tesseract程序：

```
（macOS）Tesseract 在macOS下可以使用brew安装：

brew install tesseract
非常方便，一条命令即可完成安装。
（Windows）安装Tesseract

需要先下载安装tesseract的程序，然后下载中文简体字预训练好的模型包（尽管本教程不会用tesseract，但还是给大家提供了）
```



# Pillow库

- Pillow 是一个功能强大的图像处理库，可以处理多种格式的图像文件，支持图像处理、图像增强、图像转换等多种操作。

- 因为识别图片需要用到PIL（Python Imaging Library）库中的 Image 模块

- ```
  pip install pillow
  ```

- IL的九种不同模式：`1, L, P, RGB, RGBA, CMYK, YCbCr, I, F`