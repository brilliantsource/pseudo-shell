# Pseudo-Shell
FROM scratch
ADD bin.tar.xz /
ENTRYPOINT ["/bin/sh"]
CMD ["shell"]