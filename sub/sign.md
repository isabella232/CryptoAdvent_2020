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

# sign and verify with dgst
openssl dgst -sha256 -sign private.pem data.txt > signature
openssl dgst -sha256 -verify public.pem -signature signature data.txt

# create hash from data
openssl dgst -sha256 -binary < data.txt > hash

# sign and verify with pkeyutl
openssl pkeyutl -in hash -sign -inkey private.pem -pkeyopt digest:sha256 > signature
openssl pkeyutl -in hash -verify -inkey public.pem -pubin -pkeyopt digest:sha256 -sigfile signature
```

