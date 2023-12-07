# 🖥️ image-post-processing
HDR, Histogram, Sharpen, Gamma correction, Bloom, Blur, Contour detection




## Features:

### 🖤 Black & white convert

#### Original image
> Torii
<img src="./example/gray/original_torii.jpg" width="400">

#### Average method
> Calculates the average of the Red, Green, and Blue (RGB) values of each pixel.
<img src="./example/gray/gray_average_method.jpg" width="400">

#### Weighted or luminosity method
> Human eyes are more sensitive to green. So diffrent weights are appilied to the RGB values.
```(0.299 * red) + (0.587 * green) + (0.114 * blue)```
<img src="./example/gray/gray_luminosity_method.jpg" width="400">
#### Desaturation method
> This method takes the average of the maximum and minimum values among the RGB components of each pixel.
<img src="./example/gray/gray_desaturation_method.jpg" width="400">
#### Single color channel
> This method simply uses one color channel (such as Red or Green) for the black and white conversion.
<img src="./example/gray/gray_single_channel_method.jpg" width="400">

#### Compare
> Luminosity method is the best.
<img src="./example/gray/gray_compare.gif" width="400">

### 🏎️ Blur
#### Box
#### Gaussian


## Install:
`image-post-processing` has an automatic installer.
Copy the line bellow to your console and execute it.
It will automatically download the repo, create the necessary folders.

```
bash -c "$(curl -fsSL https://raw.github.com/jeekpark/image-post-processing/main/install.sh)"
```

## Execute:
Run the command below.
```
cd ./image-post-processing
```
```
./ipp
```
