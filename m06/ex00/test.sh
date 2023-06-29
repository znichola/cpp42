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
