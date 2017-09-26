#!/usr/bin/env sh

./build/tools/caffe train \
	--solver=models/alexnet_cifar/solver_finetune.prototxt \
	--weights=models/alexnet_cifar/alexnetOriginal/best/trainAlexnetOriginal_iter_15000.caffemodel  \
	--gpu=all
