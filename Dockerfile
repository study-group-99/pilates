FROM alpine:3.13.5
RUN apk -Uuv add build-base cmake gcovr py3-pip git curl
RUN python3 -m pip install norminette
ADD pilates /bin/
ENTRYPOINT /bin/pilates
