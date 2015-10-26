BUILD_DIR = build

all: test test-run coverage

test: $(BUILD_DIR)
	cd $(BUILD_DIR); cmake $(CURDIR); make

test-run:
	$(BUILD_DIR)/calculating_test

coverage:
		lcov --capture --directory $(BUILD_DIR) \
                --output-file $(BUILD_DIR)/coverage.info
		genhtml $(BUILD_DIR)/coverage.info \
                --output-directory $(BUILD_DIR)/coverage-report

$(BUILD_DIR):
	mkdir -p $@


clean:
	rm -rf $(BUILD_DIR)

.PHONY: all cmake clean coverage test test-run
