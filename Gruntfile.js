module.exports = function(grunt) {
  var myConfig = grunt.file.readJSON('uib-w3-grunt-config.json');
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      css: {
        files: myConfig.sg + 'public/css/style.css',
        tasks: ['copy']
      }
    },
    browserSync: {
      dev: {
        bsFiles: {
          src: 'themes/uib_w3/css/*.css',
        },
        options: {
          watchTask: true,
          proxy: myConfig.proxy
        }
      }
    },
    copy: {
      dev: {
        src: myConfig.sg + 'public/css/style.css',
        dest: 'themes/uib_w3/css/style.css'
      }
    }
  });
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-browser-sync');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.registerTask('default', ['browserSync', 'watch']);
}
