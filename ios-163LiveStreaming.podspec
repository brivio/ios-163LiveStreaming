Pod::Spec.new do |s|
  s.name             = "ios-163LiveStreaming"
  s.version          = "0.1.0"
  s.summary          = "163LiveStreaming for ios development"

  s.description      = <<-DESC
                       DESC
  s.homepage         = "https://github.com/brivio/ios-163LiveStreaming"
  s.license          = 'MIT'
  s.author           = { "brivio" => "brivio@qq.com" }
  s.source           = { :git => "https://github.com/brivio/ios-163LiveStreaming.git", :tag => s.version.to_s }
  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'source/**/*.{h,m,c}'
  s.vendored_libraries  = 'source/**/*.a'
  s.vendored_frameworks  = 'source/**/*.framework'
  s.resources='source/**/*.bundle'
  s.frameworks='AudioToolbox','QuartzCore','AVFoundation','CoreMedia','UIKit','OpenGLES'
  s.libraries='z','bz2','iconv'
end
