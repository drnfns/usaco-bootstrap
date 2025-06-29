CXX = clang++
LD = lld
CXXFLAGS = -Os -s -pipe -march=native -flto=thin -fuse-ld=$(LD) -std=c++17 -stdlib=libc++ -Wall -Wextra -pedantic -fno-exceptions
SRCDIR = src
DISTDIR = dist

SOURCES = $(wildcard $(SRCDIR)/*.cxx)
TARGETS = $(patsubst $(SRCDIR)/%.cxx,$(DISTDIR)/%,$(SOURCES))

.SHELLFLAGS = -cx
.PHONY: all
all: $(TARGETS)

$(DISTDIR)/%: $(SRCDIR)/%.cxx
	@$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	@rm -rf $(DISTDIR)
	@mkdir -p $(DISTDIR)
