#!/bin/bash
cmp --silent W2.txt W1.txt && echo '### SUCCESS: Files Are Identical! ###' || echo '### WARNING: Files Are Different! ###'