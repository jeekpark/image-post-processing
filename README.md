# 🖥️ image-post-processing
HDR, Histogram, Sharpen, Gamma correction, Bloom, Blur, Contour detection


## 🖤 Black & white convert
#### Average method
> Calculates the average of the Red, Green, and Blue (RGB) values of each pixel.
#### Weighted or luminosity method
> Human eyes are more sensitive to green. So diffrent weights are appilied to the RGB values.<br>
  ```(0.3 * R) + (0.59 * G) + (0.11 * B)```
#### Desaturation method
> This method takes the average of the maximum and minimum values among the RGB components of each pixel.
#### Single color channel
> This method simply uses one color channel (such as Red or Green) for the black and white conversion.


## 🏎️ Blur
#### Box
#### Gaussian
