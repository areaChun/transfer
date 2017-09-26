#!/usr/bin/env sh

./build/tools/ristretto quantize \
	--model=models/bvlc_reference_caffenet/train_val.prototxt \
	--weights=models/bvlc_reference_caffenet/bvlc_reference_caffenet_pruned.caffemodel  \
	--model_quantized=models/bvlc_reference_caffenet/train_val_pruned_quantized.prototxt \
	--trimming_mode=dynamic_fixed_point --gpu=2 --iterations=3000 \
	--error_margin=3
