# Encryption

* AES CBC/ECB
    * change IV with every encryption!
* RSA
    * limited to key size
    * mix with AES for large files
* hash messages to avoid [bit flipping attacks](https://resources.infosecinstitute.com/topic/cbc-byte-flipping-attack-101-approach/)
* first compress, then encrypt

## Code

```bash
# data
date > data.txt

KEY=$(openssl rand -hex 16)
IV=$(openssl rand -hex 16)

# encrypt
openssl enc -e -aes-128-cbc -K "$KEY" -iv "$IV" -in data.txt -base64 > encrypted.txt
openssl enc -e -aes-128-cbc -K "$KEY" -iv "$IV" -in data.txt -base64 > encrypted2.txt
diff -sq encrypted.txt encrypted2.txt
cat encrypted.txt

#decrypt
openssl enc -d -aes-128-cbc -K "$KEY" -iv "$IV" -in encrypted.txt -base64 > decrypted.txt
diff -sq data.txt decrypted.txt
```

```bash
# data
date > data.txt
# openssl rand -hex 5000 > data.txt

# key pair
openssl genrsa -out private.pem
openssl rsa -in private.pem -out public.pem -pubout

# encrypt
openssl rsautl -encrypt -pubin -inkey public.pem -in data.txt > encrypted.txt
openssl rsautl -encrypt -pubin -inkey public.pem -in data.txt > encrypted2.txt
diff -sq encrypted.txt encrypted2.txt

#decrypt
openssl rsautl -decrypt -inkey private.pem -in encrypted.txt > decrypted.txt
diff -sq data.txt decrypted.txt
```

```bash
# large data
openssl rand -hex 5000 > data.txt

# cert for encryption
openssl req -x509 -key private.pem -subj "/CN=Hello" -days 365 -out cert.pem

# encrypt
openssl smime -encrypt -binary -aes-128-cbc -in data.txt cert.pem > encrypted.txt
openssl smime -encrypt -binary -aes-128-cbc -in data.txt cert.pem > encrypted.txt
diff -sq encrypted.txt encrypted2.txt
head -n 10 encrypted.txt

#decrypt
openssl smime -decrypt -binary -inkey private.pem -aes-128-cbc -in encrypted.txt > decrypted.txt
diff -sq data.txt decrypted.txt
```
