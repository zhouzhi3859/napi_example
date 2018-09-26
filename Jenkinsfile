pipeline {
  agent {
    label 'SWARM-NODE-NODEJS'
  }
  stages {
    stage('fetch') {
        steps {
          sh 'npm install'
          git 'https://github.com/zhouzhi3859/napi_example.git'
          sh 'cd ./napi_example'
          sh 'git checkout -b dev'
          sh 'git pull origin dev:dev'
        }
      }
    stage('build') {
      steps {
        sh 'npm install'
        sh 'npm run build'
      }
    }
  }
}
