pipeline {
  agent {
    label 'SWARM-NODE-NODEJS'
  }
  stages {
    stage('build') {
      steps {
        sh 'npm install'
        sh 'npm run build'
      }
    }
  }
}
