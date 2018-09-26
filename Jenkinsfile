pipeline {
  agent {
    label 'SWARM-NODE-NODEJS'
  }
  stages {
    stage('build') {
      steps {
        sh 'npm install'
        sh 'npm run build'
        sh '''
          export VERSION=`npm run packageVersion | awk 'END{print}'`
        '''
        sh 'echo "version = ${VERSION}"'
      }
    }
  }
}
