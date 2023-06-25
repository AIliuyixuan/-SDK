# 总的 Makefile，用于调用目录下各个子工程对应的 Makefile
# 注意： Linux 下编译方式：
# 1. 从 http://pkgman.jieliapp.com/doc/all 处找到下载链接
# 2. 下载后，解压到 /opt/jieli 目录下，保证
#   /opt/jieli/common/bin/clang 存在（注意目录层次）
# 3. 确认 ulimit -n 的结果足够大（建议大于8096），否则链接可能会因为打开文件太多而失败
#   可以通过 ulimit -n 8096 来设置一个较大的值
# 支持的目标
# make ad698n_earphone
# make ad698n_earphone_2m_flash

.PHONY: all clean ad698n_earphone ad698n_earphone_2m_flash clean_ad698n_earphone clean_ad698n_earphone_2m_flash

all: ad698n_earphone ad698n_earphone_2m_flash
	@echo +ALL DONE

clean: clean_ad698n_earphone clean_ad698n_earphone_2m_flash
	@echo +CLEAN DONE

ad698n_earphone:
	$(MAKE) -C . -f Makefile.ad698n_earphone

clean_ad698n_earphone:
	$(MAKE) -C . -f Makefile.ad698n_earphone clean

ad698n_earphone_2m_flash:
	$(MAKE) -C . -f Makefile.ad698n_earphone_2m_flash

clean_ad698n_earphone_2m_flash:
	$(MAKE) -C . -f Makefile.ad698n_earphone_2m_flash clean
