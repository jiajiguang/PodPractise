Pod::Spec.new do |s|
  s.name             = 'PodPractise'
  s.version          = '1.0.1'
  s.summary      = 'pod测试'
  s.description  = 'pod测试'
  s.homepage     = 'https://github.com/jiajiguang/PodPractise'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'jiajiguang' => '877029769@qq.com' }
  s.source       = { :git => 'https://github.com/jiajiguang/PodPractise.git', :tag => s.version.to_s }
  s.source_files = 'PodPractise/*'
  s.vendored_frameworks = 'PodPractise/MGVideo.framework'
  s.ios.deployment_target = '8.0'

end
