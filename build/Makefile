# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  material_config = debug

else ifeq ($(config),release)
  material_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := material

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

material:
ifneq (,$(material_config))
	@echo "==== Building material ($(material_config)) ===="
	@${MAKE} --no-print-directory -C . -f material.make config=$(material_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f material.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   material"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"