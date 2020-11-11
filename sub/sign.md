# Sign and Verify

# Signature

* signature = public key encrypted hash
* verify = decrypt signature and compare with hash

# Code
``` bash
# data
date > data.txt

# keys
openssl genrsa -out private.pem
openssl rsa -in private.pem -pubout > public.pem

# create hash from data
openssl dgst -sha256 -binary < data.txt > hash

# sign and verify with dgst
openssl dgst -sha256 -sign private.pem data.txt > signature
openssl dgst -sha256 -verify public.pem -signature signature data.txt
```

