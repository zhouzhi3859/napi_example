pipeline {
  agent {
    label 'SWARM-NODE-NODEJS'
  }
  stages {
    stage('fetch') {
        steps {
          sh 'git config --global user.email "zhouzhi073859@outlook.com"'
          sh 'git config --global user.name "zhouzhi"'
          git 'https://github.com/zhouzhi3859/napi_example.git'
          sh 'git checkout -b dev'
          sh ' git branch --set-upstream-to=origin/dev dev'
          sh 'git pull'
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
