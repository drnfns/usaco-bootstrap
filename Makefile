CXX = clang++
LD = lld
CXXFLAGS = -O3 -pipe -march=native -flto=thin -fuse-ld=$(LD) -std=c++17 -stdlib=libc++ -Wall -Wextra -pedantic
SRCDIR = src
DISTDIR = dist

SOURCES = $(wildcard $(SRCDIR)/*.cxx)
TARGETS = $(patsubst $(SRCDIR)/%.cxx,$(DISTDIR)/%,$(SOURCES))

.SHELLFLAGS = -cx
.PHONY: all
all: $(TARGETS)

$(DISTDIR)/%: $(SRCDIR)/%.cxx
	@mkdir -p $(DISTDIR)
	@$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	@rm -rf $(DISTDIR)
