#!/bin/bash

git clone https://github.com/jeekpark/image-post-processing.git

compiler=$(cc --version)
arch=$(uname -m)

if [[ $compiler == *"gcc"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-linux-gcc-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-macOS-clang-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "arm64" ]; then 
  sfml_bundle="SFML-2.6.1-macOS-clang-arm64.tar.gz"
fi

sfml_bundle_out=${sfml_bundle%.tar.gz}

tar -xzvf ./image-post-processing/lib/sfml/$sfml_bundle -C ./image-post-processing/lib/sfml
mv ./image-post-processing/lib/sfml/$sfml_bundle_out ./image-post-processing/lib/sfml/2.6.1
mv ./image-post-processing/lib/sfml/2.6.1/extlibs/FLAC.framework ./image-post-processing/lib/sfml/2.6.1/Frameworks/FLAC.framework
mv ./image-post-processing/lib/sfml/2.6.1/extlibs/freetype.framework ./image-post-processing/lib/sfml/2.6.1/Frameworks/freetype.framework
mv ./image-post-processing/lib/sfml/2.6.1/extlibs/ogg.framework ./image-post-processing/lib/sfml/2.6.1/Frameworks/ogg.framework
mv ./image-post-processing/lib/sfml/2.6.1/extlibs/vorbis.framework ./image-post-processing/lib/sfml/2.6.1/Frameworks/vorbis.framework
mv ./image-post-processing/lib/sfml/2.6.1/extlibs/vorbisenc.framework ./image-post-processing/lib/sfml/2.6.1/Frameworks/vorbisenc.framework
mv ./image-post-processing/lib/sfml/2.6.1/extlibs/vorbisfile.framework ./image-post-processing/lib/sfml/2.6.1/Frameworks/vorbisfile.framework



make -C image-post-processing clangd
make -C image-post-processing all


