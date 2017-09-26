#!/usr/bin/env sh

./build/tools/ristretto quantize \
	--model=models/bvlc_alexnet/train_val.prototxt \
	--weights=models/bvlc_alexnet/bvlc_alexnet_pruned.caffemodel  \
	--model_quantized=models/bvlc_alexnet/train_val_pruned_quantized.prototxt \
	--trimming_mode=dynamic_fixed_point --gpu=2 --iterations=3000 \
	--error_margin=3
