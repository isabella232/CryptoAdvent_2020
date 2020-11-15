# Sign and Verify

## Signature

* signature = public key encrypted hash
* verify = decrypt signature and compare with hash
* don't use for messaging -> better gnupg

## Code
``` bash
# data
date > data.txt

# keys
openssl genrsa -out private.pem
openssl rsa -in private.pem -pubout > public.pem
```

```bash
# sign and verify with dgst
openssl dgst -sha256 -sign private.pem data.txt > signature
openssl dgst -sha256 -verify public.pem -signature signature data.txt
```

```bash
# create hash from data
openssl dgst -sha256 -binary < data.txt > hash

# sign and verify with pkeyutl
openssl pkeyutl -in hash -sign -inkey private.pem -pkeyopt digest:sha256 > signature
openssl pkeyutl -in hash -verify -inkey public.pem -pubin -pkeyopt digest:sha256 -sigfile signature
```

```bash
# sign and verify with gnupg
gpg --output signature --detach-sig data.txt
gpg --verify signature data.txt
```
