#!/usr/bin/env sh

./build/tools/caffe train \
	--solver=models/resnet/solver_finetune.prototxt \
	--weights=models/resnet/resnet101_v2/resnet101_v2.caffemodel  \
	--gpu=0
