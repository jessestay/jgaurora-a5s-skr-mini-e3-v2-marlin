# Contributing to JGAurora A5S + SKR Mini E3 V2.0 Firmware

Thank you for your interest in contributing to this Marlin firmware configuration! This guide will help you get started.

## 🚀 Quick Start

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/amazing-feature`
3. **Make your changes**
4. **Test your changes** (compile successfully)
5. **Commit your changes**: `git commit -m 'Add amazing feature'`
6. **Push to the branch**: `git push origin feature/amazing-feature`
7. **Open a Pull Request**

## 🔧 Development Setup

### Prerequisites
- **Arduino IDE 1.8.x** (not 2.x - compatibility issues)
- **STM32duino board package**
- **Git**

### Local Build Testing
1. **Clone your fork**: `git clone https://github.com/YOUR_USERNAME/jgaurora-a5s-skr-mini-e3-v2-firmware.git`
2. **Open Arduino IDE**
3. **Select Board**: "Generic STM32F103R series" → "Generic STM32F103RE"
4. **Open**: `Marlin/Marlin.ino`
5. **Verify compilation** (Ctrl+Shift+R or Cmd+Shift+R)

### PlatformIO Testing (Optional)
1. **Install PlatformIO**: `pip install platformio`
2. **Build**: `pio run -e jgaurora_a5s_skr_mini_e3_v2`
3. **Verify**: Check for `.bin` file in `.pio/build/`

## 📋 Contribution Guidelines

### Code Style
- **Follow existing patterns** in the codebase
- **Use descriptive commit messages**
- **Test compilation** before submitting
- **Update documentation** if needed

### Configuration Changes
- **Test with actual hardware** when possible
- **Document pin changes** in setup guide
- **Verify compatibility** with SKR Mini E3 V2.0
- **Check for conflicts** with existing features

### Documentation Updates
- **Update README.md** for new features
- **Update setup guide** for wiring changes
- **Add troubleshooting** for common issues
- **Include examples** for new G-code commands

## 🐛 Bug Reports

### Before Reporting
1. **Check existing issues** for duplicates
2. **Verify your setup** matches the configuration
3. **Test with default settings**
4. **Check wiring connections**

### Bug Report Template
```markdown
**Description**
Brief description of the issue

**Hardware**
- Printer: JGAurora A5S
- Board: SKR Mini E3 V2.0
- Display: [Your display model]
- Other hardware: [Any relevant details]

**Expected Behavior**
What should happen

**Actual Behavior**
What actually happens

**Steps to Reproduce**
1. Step 1
2. Step 2
3. Step 3

**Configuration**
- Marlin version: 2.1.2.5
- Key settings: [List relevant #defines]

**Additional Information**
Any other details that might help
```

## 💡 Feature Requests

### Before Requesting
1. **Check if it's already implemented**
2. **Verify hardware compatibility**
3. **Consider impact on existing features**
4. **Research similar implementations**

### Feature Request Template
```markdown
**Feature Description**
What you'd like to see added

**Use Case**
Why this feature would be useful

**Hardware Requirements**
What hardware is needed

**Implementation Ideas**
Any thoughts on how to implement

**Related Features**
Similar features in other firmwares
```

## 🔍 Testing

### Compilation Testing
- **Verify no errors** in Arduino IDE
- **Check all features** compile correctly
- **Test with different** Arduino STM32 versions

### Hardware Testing (If Possible)
- **Test basic functionality** (movement, heating)
- **Verify display operation** (if display changes)
- **Check new features** work as expected
- **Test edge cases** and error conditions

## 📚 Resources

### Marlin Documentation
- [Marlin Official Site](https://marlinfw.org/)
- [Configuration Guide](https://marlinfw.org/docs/configuration/configuration.html)
- [G-code Reference](https://marlinfw.org/meta/gcode/)

### Hardware Documentation
- [SKR Mini E3 V2.0 Manual](https://github.com/bigtreetech/BIGTREETECH-SKR-mini-E3)
- [STM32F103 Reference](https://www.st.com/resource/en/reference_manual/cd00171190.pdf)

### Community
- [Marlin Discord](https://discord.gg/n5NJcty)
- [Reddit r/3Dprinting](https://reddit.com/r/3Dprinting)
- [GitHub Discussions](https://github.com/yourusername/jgaurora-a5s-skr-mini-e3-v2-firmware/discussions)

## 🎯 Areas for Contribution

### High Priority
- **Bug fixes** and compatibility improvements
- **Documentation** improvements and translations
- **Testing** on different hardware configurations
- **Performance** optimizations

### Medium Priority
- **New features** that don't break existing functionality
- **UI improvements** for the display
- **G-code enhancements** for better control
- **Example configurations** for similar printers

### Low Priority
- **Cosmetic changes** (unless they improve usability)
- **Experimental features** (should be clearly marked)
- **Platform-specific** optimizations

## 📝 Pull Request Process

### Before Submitting
1. **Ensure code compiles** without errors
2. **Test basic functionality** if possible
3. **Update relevant documentation**
4. **Follow commit message conventions**

### Pull Request Template
```markdown
**Description**
What does this PR do?

**Type of Change**
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Configuration change
- [ ] Other (please describe)

**Testing**
- [ ] Code compiles successfully
- [ ] Basic functionality tested
- [ ] Documentation updated
- [ ] No breaking changes

**Additional Notes**
Any other information
```

## 🏆 Recognition

Contributors will be recognized in:
- **README.md** contributors section
- **Release notes** for significant contributions
- **GitHub contributors** page
- **Community acknowledgments**

## 📞 Questions?

- **Open an issue** for bugs or feature requests
- **Start a discussion** for general questions
- **Join the community** on Discord or Reddit
- **Check existing documentation** first

Thank you for contributing to the 3D printing community! 🎉
