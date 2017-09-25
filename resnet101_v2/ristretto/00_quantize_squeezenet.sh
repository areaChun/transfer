#!/usr/bin/env sh

./build/tools/ristretto quantize \
	--model=models/resnet/resnet101_v2/resnet101_v2_cpu.prototxt \
	--weights=models/resnet/resnet101_v2/resnet101_v2.caffemodel  \
	--model_quantized=models/resnet/resnet101_v2/resnet101_cpu_quantized.prototxt \
	--trimming_mode=dynamic_fixed_point --cpu --iterations=3000 \
	--error_margin=3
