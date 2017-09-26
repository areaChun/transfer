#!/usr/bin/env sh

./build/tools/caffe test \
	--model=models/lenet/lenet_2conv2max_cccp/lenet_2conv2max_cccp_quantized.prototxt \
	--weights=models/lenet/lenet_2conv2max_cccp/lenet_2conv2max_cccp_finetuned_iter_10000.caffemodel \
	--gpu=0 --iterations=2000
