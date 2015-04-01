Pod::Spec.new do |s|
  s.name             = "Userdive-iOS-SDK"
  s.version          = "1.0.7"
  s.summary          = "USERDIVE for Apps"
  s.homepage         = "http://userdive.com"
  s.license          = { :type => 'Commercial', :text => 'See you later' }
  s.author           = { "UNCOVER TRUTH Inc." => "support@uncovertruth.jp" }

  s.platform     = :ios, '6.0'
  s.requires_arc = true
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }

  s.source           = { :git => "https://github.com/key/Userdive-iOS-SDK.git", :tag => "1.0.7" }

  s.frameworks = 'Foundation'

  s.preserve_paths      = "Userdive.framework"
  s.public_header_files = "Userdive.framework/**/*.h"
  s.vendored_frameworks = "Userdive.framework"

end
