# RSA FACTORING CHALLENGE

## Description

This is RSA Factoring Challenge not associated (but definitely inspired by) [RSA Factoring Challenge](https://en.wikipedia.org/wiki/RSA_Factoring_Challenge).

## Factors

This is the first part where you are to find the factors of `n` in the format:
`p*q`, where neither p nor q have to be prime.

The values `p` and `q` should be found in under 5 seconds

## Running

For both questions, the same program is used, but with different output names.

This is done to write the same program twice, but with different output names.

```bash
 gcc factors.c print_p.c factors -lm -lgmp
```

```bash
gcc factors.c print_p.c -o rsa -lm -lgmp
```

## Test

Tests can be created by running:

```bash
python3 _tests.py
```

You can specify the challenge (rsa or factors) in the first argument.

In the second argument you can specify the number of files to create.

If you want to create 10 files for the factors challenge, you can run:

```bash
python3 _tests.py factors 10
```
