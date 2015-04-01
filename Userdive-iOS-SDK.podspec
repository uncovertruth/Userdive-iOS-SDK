Pod::Spec.new do |s|
  s.name         = "Userdive-iOS-SDK"
  s.version      = "1.0.7"
  s.summary      = "A short description of Userdive."

  s.description  = <<-DESC
                   A longer description of Userdive in Markdown format.

                   * Think: Why did you write this? What is the focus? What does it do?
                   * CocoaPods will be using this to generate tags, and improve search results.
                   * Try to keep it short, snappy and to the point.
                   * Finally, don't worry about the indent, CocoaPods strips it!
                   DESC

  s.homepage     = "http://userdive.com"
  s.license      = { :type => "Commercial", :file => "LICENSE" }
  s.author       = { "UNCOVER TRUTH Inc." => "sales@uncovertruth.jp" }
  s.platform     = :ios, "4.3"

  s.source       = { :git => "https://github.com/key/Userdive.git", :tag => "1.0.7" }

  s.preserve_paths      = "Userdive.framework"
  s.public_header_files = "Userdive.framework/**/*.h"
  s.vendored_frameworks = "Userdive.framework"

end
