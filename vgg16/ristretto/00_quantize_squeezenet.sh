#!/usr/bin/env sh

./build/tools/ristretto quantize \
	--model=models/VGG_ILSVRC_16/train_val.prototxt \
	--weights=models/VGG_ILSVRC_16/VGG_ILSVRC_16_layers_pruned.caffemodel  \
	--model_quantized=models/VGG_ILSVRC_16/train_val_pruned_quantized.prototxt \
	--trimming_mode=dynamic_fixed_point --gpu=1 --iterations=3000 \
	--error_margin=3
