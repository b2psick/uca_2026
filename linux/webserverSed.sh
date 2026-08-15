sed -i -e 's/HTTP\/1.0/HTTP\/1.1/g' -e '/^#/d' -e 's/[0-9]\{4\}-[0-9]\{4\}-[0-9]\{4\}-[0-9]\{4\}\|[0-9]\{16\}/XXXX-XXXX-XXXX-XXXX/g' data/server_access.log

# the i is for inplace and -e for writing different commands in one go