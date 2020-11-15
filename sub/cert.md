# Certificates

* certificate = public key + metadata
* format: ASN1
* alternative: mkcert

## Code

```bash
# cert for testing
openssl req -x509 -newkey rsa:4096 -keyout key.pem -nodes -subj '/CN=localhost' -days 365 -out server.pem
openssl x509 -in server.pem -text

# serve on port 4433
openssl s_server -cert server.pem -key key.pem -www

# ASN1
openssl asn1parse -in server.pem
```
