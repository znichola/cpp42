#!/bin/bash

func ()
{
	echo ""
	echo "./cast" $@
	./cast $@
}

make re

func 0
func nan
func 42.0f
func 42.12f
func 123
func 123.123
func 1.1fff
func 1.1dd
func "'1'"
func "'3'"
func "'*'"
func nanf
func inf
func inff
func -inf
func -inff
func 43.
func .42
func 43.f
func .42f
func 2147483647
func -2147483648
func 2147483649
func 123a
func 0.0f
func 42.12f 09
