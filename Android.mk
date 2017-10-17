ifeq ($(BOARD_USES_INIT_SONY),true)

LOCAL_PATH := $(call my-dir)

include $(call all-subdir-makefiles,$(LOCAL_PATH))

endif
