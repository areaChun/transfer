#!/usr/bin/env sh

./build/tools/ristretto quantize \
	--model=models/squeezenet_v1.1/train_val.prototxt \
	--weights=models/squeezenet_v1.1/squeezenet_v1.1_pruned.caffemodel  \
	--model_quantized=models/squeezenet_v1.1/train_val_pruned_quantized.prototxt \
	--trimming_mode=dynamic_fixed_point --gpu=2 --iterations=3000 \
	--error_margin=3
