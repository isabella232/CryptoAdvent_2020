# Formats

* PKCS1
    * `-----BEGIN RSA PRIVATE KEY-----`
    * `-----BEGIN RSA PUBLIC KEY-----`

* PKCS8
    * generic key with embedded PKCS1 key
    * `-----BEGIN PRIVATE KEY-----`
    * `-----BEGIN PUBLIC KEY-----`


## Code

```bash
# PKCS1
openssl genrsa -out private_pkcs1.pem

# PKCS8
openssl pkcs8 -topk8 -inform PEM -outform PEM -nocrypt -in private_pkcs1.pem -out private_pkcs8.pem

# PKCS8
openssl rsa -in private_pkcs1.pem -out public_pkcs8.pem -outform PEM -pubout

# PKCS1
openssl rsa -in private_pkcs1.pem -RSAPublicKey_out -out public_pkcs1.pem

# for ssh
ssh-keygen -f public_pkcs8.pem -i -mPKCS8 > public.ssh
```
