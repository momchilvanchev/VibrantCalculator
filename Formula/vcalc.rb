class Vcalc < Formula
  desc "Vibrant Calculator" # Short description of the tool
  homepage "https://github.com/momchilvanchev/vibrantcalculator" # Link to the GitHub repository
  url "https://github.com/momchilvanchev/vibrantcalculator/archive/refs/tags/v1.0.tar.gz" # Link to the release tarball
  version "1.0" # Version of the release
  sha256 "28ab58e589e637dfd1e147d52937a8aa32b6f33def21767cdff1eb4d544a0d72"
  depends_on "gcc" # Ensures g++ is available for compilation

  def install
    # Compiles the program and places the executable in the 'bin' directory
    system "g++", "-o", "calc", "calculator.cpp", "-O2"
    bin.install "calc" # Installs the binary to Homebrew's bin directory
  end
end

