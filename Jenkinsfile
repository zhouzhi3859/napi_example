pipeline {
  agent {
    label 'SWARM-NODE-NODEJS'
  }
  stages {
    stage('build') {
      steps {
        sh '''
          export VERSION=`npm run packageVersion | awk 'END{print}'`
          npm install
          npm run build
          node -v
          echo "version = ${VERSION}"
        '''
      }
      }
  }
}
